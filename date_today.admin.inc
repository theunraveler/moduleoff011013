<?php

/**
 * @file
 * Contains admin UI related functionality for the Date Today module.
 */

/**
 * Implements hook_field_formatter_settings_summary_alter().
 */
function date_today_field_formatter_settings_summary_alter(&$summary, $context) {
  $settings = $context['instance']['display'][$context['view_mode']]['settings'];
  if (!empty($settings['date_today'])) {
    if (!empty($summary)) {
      $summary .= '<br />';
    }
    $summary .= t('Show option to insert the current date and time');
  }
}

/**
 * Implementation of hook_field_formatter_settings_form_alter().
 */
function date_today_field_formatter_settings_form_alter(&$form, $context) {
  if (isset($context['formatter']['settings']['date_today'])) {
    $settings = $context['instance']['display'][$context['view_mode']]['settings'];
    $form['date_today'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show option to insert the current date and time'),
      '#default_value' => $settings['date_today'],
      '#weight' => 10,
    );
  }
}

